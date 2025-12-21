#define SDA 4
#define SCL 5
#define LM75_ADDR 0x48
#define Anlog_Pin 9
#define Anlog_Waterlevel_Pin 10
#define Fan_Pin 17
#define DC_Pin 13
#define LED_Pin 16
#define DRY_SOIL 20
#define WET_SOIL 2155
#define WATER_EMPTY 5   // sensor in air
#define WATER_FULL  1371    // sensor fully in water

// ---------- Timing ----------
unsigned long lastSensorRead = 0;
const unsigned long SENSOR_INTERVAL = 2000;

// ---------- Sensor data ----------
float temperature = 0;
float humidity = 0;
float waterlevel = 0;

// ---------- FreeRTOS ----------
TaskHandle_t influxTaskHandle;
QueueHandle_t influxQueue;

// ---------- Struct for queue ----------
typedef struct {
  float temperature;
  float humidity;
  float waterlevel;
} SensorData;

