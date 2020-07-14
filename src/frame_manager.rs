extern crate sfml;

use sfml::system::Time;
use std::cmp;

#[derive(Debug)]
pub struct FrameManager
{
    estimated_frame_time: f64,
    deviation: f64
}

impl FrameManager
{
    const MIN_FRAME_TIME:f64 = 8.333; // milliseconds ~ 120 fps
    const DELTA: f64 = 0.125;
    const MU: f64 = 1.0;
    const PHI:f64 = 4.0;

    pub fn new() -> FrameManager
    {
        FrameManager{
            estimated_frame_time: Self::MIN_FRAME_TIME * 2.0,
            deviation: 0.0
        }

    }
    pub fn get_wait_time(&mut self, computation_time: Time) -> Time
    {
        let sample_frame_time = computation_time.as_milliseconds() as f64;
        // let draw = draw_time as f64;
        let difference = sample_frame_time - self.estimated_frame_time;
        self.estimated_frame_time += Self::DELTA * difference;
        self.deviation += Self::DELTA * ( difference.abs() - self.deviation );
        let mut time_out = Self::MU * self.estimated_frame_time + Self::PHI * self.deviation;
        if time_out < Self::MIN_FRAME_TIME
        {
            time_out = Self::MIN_FRAME_TIME;
        }
        Time::milliseconds(time_out as i32)
    }
}
