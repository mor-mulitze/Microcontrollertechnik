#include <driver/rmt.h>
#include <driver/periph_ctrl.h>

rmt_item32_t items[] = {
  {{{ 32767, 1, 32767, 0 }}},
  {{{ 32767, 1, 32767, 0 }}},
  {{{ 32767, 1, 32767, 0 }}},
  {{{ 0, 0, 0, 0 }}},
};

void setup() 
{
  rmt_config_t rmt_tx;
  rmt_tx.rmt_mode = RMT_MODE_TX;
  rmt_tx.channel = RMT_CHANNEL_0;
  rmt_tx.gpio_num = GPIO_NUM_2;                   //onboard visible LED
  rmt_tx.mem_block_num = 1;
  rmt_tx.clk_div = 255;
  rmt_tx.tx_config.loop_en = false;
  rmt_tx.tx_config.carrier_en = false;                    // \/Fix for below issue?

  rmt_tx.tx_config.carrier_duty_percent = 50;
  rmt_tx.tx_config.carrier_freq_hz = 38000;
  rmt_tx.tx_config.carrier_level = (rmt_carrier_level_t)1;

  rmt_tx.tx_config.idle_level = (rmt_idle_level_t)0;
  rmt_tx.tx_config.idle_output_en = true;

  ESP_LOGI(TAG, "rmt_config");
  ESP_ERROR_CHECK(rmt_config(&rmt_tx));
  
  //install system RMT driver, disable rx ringbuffer for transmitter.
  ESP_LOGI(TAG, "rmt_driver_install");
  ESP_ERROR_CHECK(rmt_driver_install(rmt_tx.channel, 0, 0));

  rmt_fill_tx_items(rmt_tx.channel, (const rmt_item32_t*) items, sizeof(items) / sizeof(rmt_item32_t), 0);
  rmt_tx_start(rmt_tx.channel, true);

//  periph_module_enable(PERIPH_RMT_MODULE);
//  *((volatile uint32_t *) (0x3FF000C0)) |= 0x200 ;
//  *((volatile uint32_t *) (0x3FF000C4)) &= (~(0x200)) ;
}


void loop()
{
}

/*

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

*/