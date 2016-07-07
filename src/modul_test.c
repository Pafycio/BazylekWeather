#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "modul.h"
#include "modul_controller.h"

// HELP FUNCTION

void add_test_moduls_to_controller(Controller *c)
{
    addModulToController(makeModul(1, temp), c);
    addModulToController(makeModul(2, hPa), c);
    addModulToController(makeModul(3, PM25), c);
    addModulToController(makeModul(4, PM10), c);
}

// TEST CASE

void test_init_model()
{
    RUN(__func__);
    Modul *m1 = makeModul(10, PM10);
    setPin(m1, 14);
    setType(m1, PM25);

    assert_int_eq(getPin(m1), 14);
    assert_eq(getType(m1) == PM25);
    freeModul(m1);
}

void test_set_model_data()
{
    RUN(__func__);
    Modul *m1 = makeModul(10, PM10);
    setData(m1, "Some Data");
    assert_int_eq(getPin(m1), 10);
    assert_eq(getType(m1) == PM10);
    assert_str_eq(getData(m1), "Some Data");
    setData(m1, "ChangedData");
    assert_str_eq(getData(m1), "ChangedData");
    freeModul(m1);
}

void test_init_controller()
{
    RUN(__func__);
    Controller *c = makeController();
    assert_int_eq(c->modulsCount, 0);
    freeController(c);
}

void test_controller_with_moduls()
{
    RUN(__func__);
    Controller *c = makeController();

    addModulToController(makeModul(5, PM10), c);
    addModulToController(makeModul(12, PM10), c);
    addModulToController(makeModul(53, PM10), c);
    addModulToController(makeModul(555, PM10), c);

    assert_int_eq(c->modulsCount, 4);
    assert_int_eq(getPin(c->moduls[3]), 555);

    freeController(c);
}

void test_emit_update_moduls()
{
    RUN(__func__);
    Controller *c = makeController();
    add_test_moduls_to_controller(c);
    ASSERT_BLOCK("Check empty data");
    for (size_t i = 0; i < c->modulsCount; ++i)
        assert_str_not_eq(getData(c->moduls[i]), "TEST");

    updateModulsInfo(c);
    ASSERT_BLOCK("Check updated data");
    for (size_t i = 0; i < c->modulsCount; ++i)
        assert_str_eq(getData(c->moduls[i]), "TEST");
}

int main(void)
{
    test_init_model();
    test_set_model_data();
    test_init_controller();
    test_controller_with_moduls();
    test_emit_update_moduls();
}
