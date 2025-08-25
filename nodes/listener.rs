use std::env;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let context = rclrs::Context::new(env::args())?;
    let node = rclrs::create_node(&context, "listener")?;

    let _subscription = node.create_subscription(
        "topic",
        rclrs::QOS_PROFILE_DEFAULT,
        |msg: std_msgs::msg::String| {
            println!("Received message: {}", msg.data);
        },
    )?;

    rclrs::spin(node)?;
    Ok(())
}
