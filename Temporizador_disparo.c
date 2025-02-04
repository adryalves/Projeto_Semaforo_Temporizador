#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define LED_AZUL 13    // GPIO do LED azul
#define LED_AMARELO 12 // GPIO do LED amarelo
#define LED_VERDE 11   // GPIO do LED verde
#define BUTTON 5       // GPIO do botão

volatile bool executando = false; // Indica se o temporizador está em execução

// Callback para desligar o último LED
int64_t desligar_led_verde(alarm_id_t id, void *user_data)
{
    gpio_put(LED_VERDE, 0);
    executando = false; // Permite novo acionamento pelo botão
    return 0;
}

// Callback para desligar o LED amarelo e programar o desligamento do verde
int64_t desligar_led_amarelo(alarm_id_t id, void *user_data)
{
    gpio_put(LED_AMARELO, 0);
    add_alarm_in_ms(3000, desligar_led_verde, NULL, false);
    return 0;
}

// Callback para desligar o LED azul e programar o desligamento do amarelo
int64_t desligar_led_azul(alarm_id_t id, void *user_data)
{
    gpio_put(LED_AZUL, 0);
    add_alarm_in_ms(3000, desligar_led_amarelo, NULL, false);
    return 0;
}

// Função para detectar o pressionamento do botão
void check_button()
{
    if (!executando && gpio_get(BUTTON) == 0)
    { // Botão pressionado (ativo em nível baixo)
        executando = true;
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 1);
        add_alarm_in_ms(3000, desligar_led_azul, NULL, false);
    }
}

int main()
{
    stdio_init_all();

    gpio_init(LED_AZUL);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_init(BUTTON);

    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    while (true)
    {
        check_button();
        sleep_ms(100);
    }
}
