#include <gmock/gmock.h>
#include "pizza_store_nvi.cpp"
#include <stdexcept>


class Mdps : public DeliciousPizzaStore {
public:
MOCK_METHOD((void), MakePizza, (), ());
};

class Mpps : public PoorPizzaStore {
public:
MOCK_METHOD((void), MakePizza, (), ());
};
TEST (Print_test, pt) {
  DeliciousPizzaStore deliciousPizzaStore;
  testing::internal::CaptureStdout();
  deliciousPizzaStore.MakePizza();
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "Make delicious dough!\nPut delicious topping!\nBake pizza in an expensive oven!\n");
}
using ::testing::AtLeast;
TEST (Delicious_Pizza_Test, dpt) {
  Mdps test_obj;
  EXPECT_CALL(test_obj, MakePizza()).Times(AtLeast(1));
  test_obj.MakePizza();
}
TEST (Poor_Pizza_Test, ppt) {
  Mpps test_obj3;
  EXPECT_CALL(test_obj3, MakePizza()).Times(AtLeast(1));
  test_obj3.MakePizza();
}


