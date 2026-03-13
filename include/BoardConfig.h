#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

// Board identification and pin configuration

#ifdef BOARD_SUPERMINI
  #define BOARD_NAME "ESP32-S3-DevKitC-1 (SuperMini)"
  #define BOARD_TYPE_SUPERMINI
  
#elif defined(BOARD_XIAO)
  #define BOARD_NAME "XIAO ESP32S3" 
  #define BOARD_TYPE_XIAO

#elif defined(BOARD_NODEMCU_ESP32)
  #define BOARD_NAME "NodeMCU ESP32 WROOM-32"
  #define BOARD_TYPE_NODEMCU_ESP32
  
#else
  #define BOARD_NAME "ESP32-S3 (Unknown)"
  #define BOARD_TYPE_SUPERMINI  // Default fallback
  
#endif

// Pin definitions
#ifdef BOARD_TYPE_NODEMCU_ESP32
  // NodeMCU ESP32 WROOM-32 mappings
  #define HX711_DATA_PIN      34  // GPIO34 - HX711 Data pin (input-only)
  #define HX711_CLOCK_PIN     25  // GPIO25 - HX711 Clock pin
  #define TOUCH_TARE_PIN      33  // GPIO33 - Touch sensor for tare
  #define TOUCH_SLEEP_PIN     32  // GPIO32 - Touch sensor for sleep / deep sleep wake (RTC GPIO)
  #define BATTERY_PIN         35  // GPIO35 - Battery voltage monitoring (ADC1 input-only)
  #define I2C_SDA_PIN         21  // GPIO21 - I2C Data pin for display
  #define I2C_SCL_PIN         22  // GPIO22 - I2C Clock pin for display
#else
  // ESP32-S3 board mappings
  #define HX711_DATA_PIN      5   // GPIO5 - HX711 Data pin
  #define HX711_CLOCK_PIN     6   // GPIO6 - HX711 Clock pin
  #define TOUCH_TARE_PIN      4   // GPIO4 - Touch sensor for tare (T0)
  #define TOUCH_SLEEP_PIN     3   // GPIO3 - Touch sensor for sleep functionality
  #define BATTERY_PIN         7   // GPIO7 - Battery voltage monitoring (ADC1_CH6)
  #define I2C_SDA_PIN         8   // GPIO8 - I2C Data pin for display
  #define I2C_SCL_PIN         9   // GPIO9 - I2C Clock pin for display
  #define I2C2_SDA_PIN        2   // GPIO2 - I2C Data pin for second display (separate bus)
  #define I2C2_SCL_PIN        1   // GPIO1 - I2C Clock pin for second display (separate bus)
#endif

// Board-specific configurations
#ifdef BOARD_TYPE_SUPERMINI
  #define FLASH_SIZE_MB       4
  #define BOARD_DESCRIPTION   "ESP32-S3 SuperMini with 4MB Flash"
  
#elif defined(BOARD_TYPE_XIAO)
  #define FLASH_SIZE_MB       8
  #define BOARD_DESCRIPTION   "XIAO ESP32S3 with 8MB Flash"

#elif defined(BOARD_TYPE_NODEMCU_ESP32)
  #define FLASH_SIZE_MB       4
  #define BOARD_DESCRIPTION   "NodeMCU ESP32 WROOM-32 with 4MB Flash"
  
#endif

// Common ESP32-S3 features available on both boards
#define HAS_WIFI            true
#define HAS_BLUETOOTH       true
#ifdef BOARD_TYPE_NODEMCU_ESP32
  #define HAS_PSRAM         false
#else
  #define HAS_PSRAM         true
#endif
#define HAS_TOUCH_SENSOR    true
#define ADC_RESOLUTION      12    // 12-bit ADC
#define PWM_RESOLUTION      8     // 8-bit PWM

#endif // BOARD_CONFIG_H