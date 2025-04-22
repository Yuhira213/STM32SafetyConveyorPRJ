#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "relay_buzzer.h"  // Sertakan header untuk deklarasi

// Unit test untuk sistem kontrol relay dan buzzer
static void test_normal_operation(void **state) { //Test case ketika dalam kondisi normal//
    int relay = 1, buzzer = 0;
    control_relay_buzzer(0, 0, &relay, &buzzer);
    assert_int_equal(relay, 1);  // Relay harus hidup
    assert_int_equal(buzzer, 0); // Buzzer harus mati
}

static void test_photoelectric_detection(void **state) { //Test Case ketika Photoelectric mendeteksi adanya objek asing//
    int relay = 1, buzzer = 0;
    control_relay_buzzer(1, 0, &relay, &buzzer);
    assert_int_equal(relay, 0);  // Relay harus mati
    assert_int_equal(buzzer, 1); // Buzzer harus hidup
}

static void test_button_press_without_object(void **state) { //Test Case ketika pushbutton ditekan ketika sensor sudah tidak mendeteksi adanya objek asing//
    int relay = 0, buzzer = 1;
    control_relay_buzzer(0, 1, &relay, &buzzer);
    assert_int_equal(relay, 1);  // Relay hidup
    assert_int_equal(buzzer, 0); // Buzzer mati
}

static void test_button_press_with_object(void **state) { //Test Case ketika pushbutton ditekan ketika sensor tetap mendeteksi adanya objek asing//
    int relay = 0, buzzer = 1;
    control_relay_buzzer(1, 1, &relay, &buzzer);
    assert_int_equal(relay, 0);  // Relay tetap mati
    assert_int_equal(buzzer, 1); // Buzzer tetap hidup
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_normal_operation),
        cmocka_unit_test(test_photoelectric_detection),
        cmocka_unit_test(test_button_press_without_object),
        cmocka_unit_test(test_button_press_with_object),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
