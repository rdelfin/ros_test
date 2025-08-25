#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Listener : public rclcpp::Node {
public:
  Listener() : Node("listener") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10,
        [this](const std_msgs::msg::String::SharedPtr msg) -> void {
          RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
        });
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Listener>());
  rclcpp::shutdown();
  return 0;
}
