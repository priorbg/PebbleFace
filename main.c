#include <pebble.h>
//Declarar Variavéis  
static Window *s_main_window;
static TextLayer *DD;
static TextLayer *MO;
static TextLayer *YY;
static TextLayer *HH;
static TextLayer *MM;
static TextLayer *SS;
static TextLayer *WW;
static GFont font;
  static void update_time() {
  //Get a TM structure
    time_t temp = time(NULL); 
    struct tm *tick_time = localtime(&temp);
  //Create a long-lived buffer
    static char bH[] = "HH";
    static char bM[] = "MM";
    static char bS[] = "SS";
    static char bD[] = "DD";
    static char bMo[] = "MO";
    static char bY[] = "YYYY";
    static char bW[] = "WEEKDAYSZ";
  //Escrevendo o tempo nos buffers
    if(clock_is_24h_style() == true) //24h formato
		{
    		strftime(bH, sizeof("HH"),"%H", tick_time);
        strftime(bM, sizeof("MM"),"%M", tick_time);
        strftime(bS, sizeof("SS"),"%S", tick_time);
		} 
    else 
		{
  //12h formato
        strftime(bH, sizeof("HH"),"%I", tick_time);
        strftime(bM, sizeof("MM"),"%M", tick_time);
        strftime(bS, sizeof("SS"),"%S", tick_time);
		}
    strftime(bD, sizeof("DD"),"%d", tick_time);
    strftime(bMo, sizeof("MO"),"%m", tick_time);
    strftime(bY, sizeof("YYYY"),"%G", tick_time);
    strftime(bW, sizeof("WEEKDAYSZ"),"%A", tick_time);
		//Mostrar tempo TextLayer - Ordem da Tela
  		text_layer_set_text(DD, bD);
  		text_layer_set_text(MO, bMo);
			text_layer_set_text(YY, bY);
		text_layer_set_text(HH, bH);
  	text_layer_set_text(MM, bM);
	text_layer_set_text(WW, bW);
	text_layer_set_text(SS, bS);
}
  static void main_window_load(Window *window) {
  //INICIO TELA - CIMA
  //DIA
    DD = text_layer_create(GRect(2, 0, 100, 100));
    text_layer_set_background_color(DD, GColorClear);
    text_layer_set_text_color(DD, GColorBlack);
    text_layer_set_text(DD, "DD");
  	//Propriedades
    text_layer_set_font(DD, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
    text_layer_set_text_alignment(DD, GTextAlignmentLeft );
  	//MÊS
    MO = text_layer_create(GRect(19, 0, 100, 100));
    text_layer_set_background_color(MO, GColorClear);
    text_layer_set_text_color(MO, GColorBlack);
    text_layer_set_text(MO, "MO");
  	//Propriedades
    text_layer_set_font(MO, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
    text_layer_set_text_alignment(MO, GTextAlignmentCenter );
  	//ANO
    YY = text_layer_create(GRect(43, 0, 100, 100));
    text_layer_set_background_color(YY, GColorClear);
    text_layer_set_text_color(YY, GColorBlack);
    text_layer_set_text(YY, "YYYY");
  	//Propriedades
    text_layer_set_font(YY, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
    text_layer_set_text_alignment(YY, GTextAlignmentRight );
  
  //MEIO DA TELA
  //HORA
      HH = text_layer_create(GRect(0, 35, 145, 75));
      text_layer_set_background_color(HH, GColorClear);
      text_layer_set_text_color(HH, GColorBlack);
      text_layer_set_text(HH, "HH");
  	//Propriedades 
      text_layer_set_font(HH, font);
      text_layer_set_text_alignment(HH, GTextAlignmentCenter);
  //MINUTOS
      MM = text_layer_create(GRect(0, 80, 145, 75));
      text_layer_set_background_color(MM, GColorClear);
      text_layer_set_text_color(MM, GColorBlack);
      text_layer_set_text(MM, "MM");
  	//Propriedades
      text_layer_set_font(MM, font);
      text_layer_set_text_alignment(MM, GTextAlignmentCenter );
  
  //FIM TELA - BAIXO
  //SEMANA
    WW = text_layer_create(GRect(3, 145, 139, 50));
    text_layer_set_background_color(WW, GColorClear);
    text_layer_set_text_color(WW, GColorBlack);
    text_layer_set_text(WW, "WEEKDAYSZ");
  	//Propriedades
    text_layer_set_font(WW, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
    text_layer_set_text_alignment(WW, GTextAlignmentLeft );
  //SEGUNDOS
    SS = text_layer_create(GRect(4, 145, 139, 50));
    text_layer_set_background_color(SS, GColorClear);
    text_layer_set_text_color(SS, GColorBlack);
    text_layer_set_text(SS, "SS");
  	//Propriedades
    text_layer_set_font(SS, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
    text_layer_set_text_alignment(SS, GTextAlignmentRight );
  //outras COISAS DA TELA
  //GFont
    font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_IMG_54));
  // IMPORTANTE: Adiciona os campos como filho para mostrar na tela
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(DD));
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(MO));
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(YY));
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(HH));
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(MM));
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(SS));
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(WW));
  //Mostrar tempo
  update_time();
}
  static void main_window_unload(Window *window) {
  // Destroy TextLayer
		fonts_unload_custom_font(font);
    text_layer_destroy(DD);
    text_layer_destroy(MO);
    text_layer_destroy(YY);
    text_layer_destroy(HH);
    text_layer_destroy(MM);
    text_layer_destroy(SS);
    text_layer_destroy(WW);
}
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}
static void init() {
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(s_main_window, true);
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}
static void deinit() {
  window_destroy(s_main_window);
}
int main(void) {
  init();
  app_event_loop();
  deinit();
}