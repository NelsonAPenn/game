#![allow(dead_code)]

extern crate sfml;
mod vector;
mod frame_manager;

use frame_manager::FrameManager;

use sfml::{
    graphics::{
        CircleShape, Color, RenderWindow, RenderTarget, Transformable, Shape
    },
    system::{Clock, Time, sleep},
    window::{ContextSettings, Event, Style},
};

const SCHMECS_CONVERSION: f64 = 0.1; // schmecs / millisecond

fn to_schmecs (t: Time) -> f64
{
    f64::from(t.as_milliseconds()) * SCHMECS_CONVERSION
}

fn to_time (schmecs: f64) -> Time
{
    Time::milliseconds((schmecs / SCHMECS_CONVERSION) as i32)
}

fn main() {
    // in main and frame_manager, we use system time. In Physics, we use schmix and schmecs
    let mut clock = Clock::start();

    let context_settings = ContextSettings {
        antialiasing_level: 0,
        ..Default::default()
    };
    let mut window = RenderWindow::new(
        (200, 200),
        "COOL GAME",
        Style::CLOSE,
        &context_settings,
    );
    let mut frame_manager = FrameManager::new();
    // let mut physics = Physics::new();
    let mut circle = CircleShape::new(100.0, 600);
    circle.set_fill_color(Color::GREEN);
    circle.set_origin((100.0, 100.0));
    let mut first_frame_shown = false;
    // start main game loop
    loop
    {
        // track the time for computation before drawing
        let draw_time = clock.restart();
        // check for events (closed, keyboard, mouse, etc)
        while let Some(event) = window.poll_event()
        {
            match event
            {
                Event::Closed => 
                {
                    window.close();
                    break;
                },
                _ => {}
            }
        }
        // main computation occurs here. Call functions in physics, etc.
        // wait the rest of the time necessary given by the frame manager
        let computation_time = clock.elapsed_time();
        if first_frame_shown
        {
            sleep(frame_manager.get_wait_time(computation_time));
            println!("{:?}", frame_manager);
        }
        else
        {
            first_frame_shown = true;
        }
        // TODO: call frame manager
        // sleep(frame_manager.get_wait_time(computation_time))
        // clear then draw
        window.clear(Color::rgb(255,255,0));
        window.draw(&circle);
        window.display();

    }


}
