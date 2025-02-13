#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

class TeleportClient : public rclcpp::Node {
    public:
        TeleportClient() : Node("client_test_node_cpp") {
            client_ = this->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");

            while (!client_->wait_for_service(1s)) {
                RCLCPP_WARN(this->get_logger(), "Waiting for service...");
            }

            auto request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
            request->x = 1.0;
            request->y = 1.1;
            request->theta = 3.14;

            auto result_future = client_->async_send_request(request);

            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future) == rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_INFO(this->get_logger(), "Service all succedded");
            } else {
                RCLCPP_ERROR(this->get_logger(), "Failed to call service");
            }
        }

        private:
            rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr client_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TeleportClient>());
    rclcpp::shutdown();
    return 0;
}