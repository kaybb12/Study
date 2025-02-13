#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class TwistPublisher : public rclcpp::Node
{
    public:
        TwistPublisher() : Node("pub_test_cpp"), count_(0)
        {
            publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        
            timer_ = this->create_wall_timer(
                std::chrono::milliseconds(100),
                std::bind(&TwistPublisher::timer_callback, this)
            );
        }

    private:
        void timer_callback() {
            count_++;
            auto message = geometry_msgs::msg::Twist();

            message.linear.x = 2.0;
            message.angular.z = 2.0;

            RCLCPP_INFO(this->get_logger(), "Publishing Twist: linear.x=%.2f, angular.z=%.2f", message.linear.x, message.angular.z);
            publisher_->publish(message);

            if (count_ > 3) {
                RCLCPP_WARN(this->get_logger(), "Publish Stopped");
                rclcpp::shutdown();
            }
        }

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        int count_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TwistPublisher>());
    rclcpp::shutdown();
    return 0;
}