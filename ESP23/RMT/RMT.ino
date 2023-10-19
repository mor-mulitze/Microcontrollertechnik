#include <driver/rmt.h>
#include <driver/periph_ctrl.h>
  
void setup() 
{
  rmt_config_t rmt_tx;
  rmt_tx.channel = RMT_CHANNEL_0;
  rmt_tx.gpio_num = GPIO_NUM_2;                   //onboard visible LED
  rmt_tx.mem_block_num = 1;
  rmt_tx.clk_div = 250;
  rmt_tx.tx_config.loop_en = false;
  rmt_tx.tx_config.carrier_duty_percent = 50;
  rmt_tx.tx_config.carrier_freq_hz = 38000;
  rmt_tx.tx_config.carrier_level = (rmt_carrier_level_t)1;
  rmt_tx.tx_config.carrier_en = false;                    // \/Fix for below issue?
//  rmt_tx.tx_config.carrier_en = RMT_TX_CARRIER_EN;      //Not in rmt driver at all?
  rmt_tx.tx_config.idle_level = (rmt_idle_level_t)0;
  rmt_tx.tx_config.idle_output_en = true;
  rmt_tx.rmt_mode = RMT_MODE_TX;
  rmt_config(&rmt_tx);
  
  rmt_item32_t items[3];
  items[0].duration0 = 32767;
  items[0].level0 = 1;
  items[0].duration1 = 32767;
  items[0].level1 = 0;
  items[1].duration0 = 32767;
  items[1].level0 = 1;
  items[1].duration1 = 32767;
  items[1].level1 = 0;

//install system RMT driver, disable rx ringbuffer for transmitter.
  rmt_driver_install(rmt_tx.channel, 0, 0);
  //rmt_write_items(rmt_tx.channel, (rmt_item32_t*) items, 4, false); //replaced by??
  rmt_fill_tx_items(rmt_tx.channel, (rmt_item32_t*) items, 4, (DR_REG_RMT_BASE + 0x800 + 0x40 * 4));
  rmt_tx_start(rmt_tx.channel, true);

  periph_module_enable(PERIPH_RMT_MODULE);
  *((volatile uint32_t *) (0x3FF000C0)) |= 0x200 ;
  *((volatile uint32_t *) (0x3FF000C4)) &= (~(0x200)) ;
}

void loop() 
{
}


rmt_item32_t items[] = {
    {{{ 50, 0, 50, 0 }}},
    {{{ 2, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 1, 1, 1, 0 }}},
    {{{ 0, 0, 0, 0 }}},
};

void app_main(void *ignore)
{
    rmt_config_t config;
    config.rmt_mode = RMT_MODE_TX;
    config.channel = RMT_CHANNEL_0;
    config.gpio_num = 12;
    config.mem_block_num = 1;
    config.tx_config.carrier_en = 0;
    // config.tx_config.loop_en = 1;
    config.tx_config.loop_en = false;
    config.tx_config.idle_output_en = 1;
    config.tx_config.idle_level = 0;
    config.clk_div = 10;

    ESP_LOGI(TAG, "rmt_config");
    ESP_ERROR_CHECK(rmt_config(&config));
    ESP_LOGI(TAG, "rmt_driver_install");
    ESP_ERROR_CHECK(rmt_driver_install(config.channel, 0, 0));
    int number_of_items = sizeof(items) / sizeof(rmt_item32_t);
    ESP_LOGI(TAG, "rmt_write_items");
    // ESP_ERROR_CHECK(rmt_write_items(RMT_CHANNEL_0, items, number_of_items, false));
    rmt_fill_tx_items(RMT_CHANNEL_0, (const rmt_item32_t *)items, number_of_items, 0);
    rmt_set_tx_intr_en(RMT_CHANNEL_0, false);
    rmt_set_tx_loop_mode(RMT_CHANNEL_0, true);
    while (1) {
        ESP_LOGI(TAG, "Waitink");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}


from micropython import const
from machine import mem32

# Define the register addresses that will be used.
DR_REG_DPORT_BASE = const(0x3FF00000)
DPORT_PERIP_CLK_EN_REG = const(DR_REG_DPORT_BASE + 0x0C0)
DPORT_PERIP_RST_EN_REG = const(DR_REG_DPORT_BASE + 0x0C4)
DPORT_PWM0_CLK_EN = const(1 << 17)
MCPWM0 = const(0x3FF5E000)
MCPWM1 = const(0x3FF6C000)

# Enable CLK and disable RST.
print(hex(mem32[DPORT_PERIP_CLK_EN_REG] & 0xffffffff))
print(hex(mem32[DPORT_PERIP_RST_EN_REG] & 0xffffffff))
mem32[DPORT_PERIP_CLK_EN_REG] |= DPORT_PWM0_CLK_EN
mem32[DPORT_PERIP_RST_EN_REG] &= ~DPORT_PWM0_CLK_EN
print(hex(mem32[DPORT_PERIP_CLK_EN_REG] & 0xffffffff))
print(hex(mem32[DPORT_PERIP_RST_EN_REG] & 0xffffffff))

# Change the MCPWM0 prescaler.
print(hex(mem32[MCPWM0])) # read PWM_CLK_CFG_REG (reset value = 0)
mem32[MCPWM0] = 0x55      # change PWM_CLK_PRESCALE
print(hex(mem32[MCPWM0])) # read PWM_CLK_CFG_REG