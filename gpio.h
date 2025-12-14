#define SDA 4
#define SCL 5
#define LM75_ADDR 0x48
#define Anlog_Pin 9
#define Anlog_Waterlevel_Pin 10
#define DC_Pin 13
#define LED_Pin 16
#define DRY_SOIL 3800
#define WET_SOIL 600
#define WATER_EMPTY 3900   // sensor in air
#define WATER_FULL  600    // sensor fully in water
float temperature;
float humidity;
float waterlevel;
