#include "app_test.h"
#include "rtc.h"

AppInfo appInfo_test = {
	APP_TEST_ID,
	&app_test_start,
	&app_test_stop,
	&app_test_draw,
	&app_test_update,
	&app_test_input_handler
};

AppInfo* app_test(void)
{
	slog("test app");
	return &appInfo_test;
	
}

GUI_ListData* list;

uint8_t app_test_start(void)
{
	
	
	
	slog("test started");
	return SYS_OK;
}
uint8_t app_test_stop(void)
{
	return SYS_OK;
}
char LKey = 11;
uint32_t LArg = 13, cnt = 0;

void app_test_draw(void)
{
	gui_rect_fill(0,7, LArg/70, 64, 1, 1); 
	
	char bu[30] = {0};
	RTC_TimeTypeDef time;
	HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
	sprintf(bu, "%d:%d:%d    %d", time.Hours, time.Minutes, time.Seconds, cnt);
	gui_lable(bu, 0, 7, 128, 20, 1, 1);
	memset(bu, 0, sizeof(bu));
	sprintf(bu, "key: %c\narg: %d", keyboard_key_to_char(LKey), LArg);
	gui_lable(bu, 0, 30, 128, 33, 1, 1);
}
void app_test_update(void)
{
}
void app_test_input_handler(int8_t key, uint32_t arg)
{
	LKey = key;
	LArg = arg;
	if(arg == 0)
		cnt ++;
}
