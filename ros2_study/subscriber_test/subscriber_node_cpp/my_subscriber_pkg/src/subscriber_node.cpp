#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"

class MinimalSubscriber : public rclcpp::Node
{
    public:
        MinimalSubscriber()
        : Node("sub_test_cpp")
        {
            subscription_ = this->create_subscription<turtlesim::msg::Pose>(
                "/turtle1/pose", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
        }


private:
    void topic_callback(const turtlesim::msg::Pose::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "/turtle1/pose: x = %.2f, y = %.2f, theta = %.2f", msg->x, msg->y, msg->theta);
    }

    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}