/**
 * @file gpio.h
 * @author Francois Berder
 * @date 2016
 * @copyright 3-clause BSD
 */


#ifndef __LETMECREATE_CORE_GPIO_H__
#define __LETMECREATE_CORE_GPIO_H__

#include <stdint.h>


/** GPIO pin number */
enum GPIO_PIN {
    MIKROBUS_1_AN  = 22,
    MIKROBUS_1_RST = 23,
    MIKROBUS_1_PWM = 73,
    MIKROBUS_1_INT = 21,
    MIKROBUS_2_AN  = 25,
    MIKROBUS_2_RST = 27,
    MIKROBUS_2_PWM = 74,
    MIKROBUS_2_INT = 24,

    GPIO_14        = 14,
    GPIO_21        = 21,
    GPIO_22        = 22,
    GPIO_23        = 23,
    GPIO_24        = 24,
    GPIO_25        = 25,
    GPIO_27        = 27,
    GPIO_31        = 31,
    GPIO_73        = 73,
    GPIO_74        = 74,
    GPIO_75        = 75,
    GPIO_88        = 88,
    GPIO_89        = 89,

    /* GPIO on Raspberry Pi interface only */
    GPIO_72        = 72,
    GPIO_80        = 80,
    GPIO_81        = 81,
    GPIO_82        = 82,
    GPIO_83        = 83,
    GPIO_84        = 84,
    GPIO_85        = 85
};

/** GPIO direction */
enum GPIO_DIR {
    GPIO_OUTPUT,
    GPIO_INPUT
};

/**
 * @brief Initialise a GPIO.
 *
 * Export a GPIO if needed and configure it as an input
 *
 * @param[in] gpio_pin Index of the GPIO
 * @return 0 if successful, -1 otherwise
 */
int gpio_init(uint8_t gpio_pin);

/**
 * @brief Configure GPIO as input or output.
 *
 * @param[in] gpio_pin Index of the GPIO
 * @param[in] dir Direction of the gpio (must be GPIO_OUTPUT or GPIO_INPUT)
 * @return 0 if successful, -1 otherwise
 */
int gpio_set_direction(uint8_t gpio_pin, uint8_t dir);

/**
 * @brief Get the direction of a GPIO.
 *
 * @param[in] gpio_pin Index of the GPIO
 * @param[out] dir Pointer to a variable (must not be null)
 * @return 0 if successful, -1 otherwise
 */
int gpio_get_direction(uint8_t gpio_pin, uint8_t *dir);

/**
 * @brief Set the output state (high or low) of a GPIO
 *
 * The GPIO must be configured as an output.
 *
 * @param[in] gpio_pin Index of the GPIO
 * @param[in] value (0: low, any other value: high)
 * @return 0 if successful, -1 otherwise
 */
int gpio_set_value(uint8_t gpio_pin, uint8_t value);

/**
 * @brief Get the output state of a GPIO.
 *
 * @param[in] gpio_pin Index of the GPIO
 * @param[out] value Pointer to a variable (must not be null)
 * @return 0 if successful, -1 otherwise
 */
int gpio_get_value(uint8_t gpio_pin, uint8_t *value);

/**
 * @brief Release a GPIO.
 *
 * Unexport a GPIO if needed.
 *
 * @param gpio_pin Index of the GPIO
 * @return 0 if successful, -1 otherwise
 */
int gpio_release(uint8_t gpio_pin);

#endif
