extern crate sfml;

mod vector;
use sfml::graphics::Shape;

#[derive(Clone, Debug)]
pub enum CollisionBehavior
{
    ELASTIC,
    INELASTIC,
    P_ELASTIC,
    P_INELASTIC,
}

#[derive(Clone, Debug)]
pub struct Object
{
    mobile: bool,
    grounded: bool,
    mass: f64,
    hit_type: CollisionBehavior, // maybe elasticity: f64
    position: Vector,
    velocity: Vector,
    acceleration: Vector, // maybe don't need this, depending on how we implement forces
    hit_box: Vec<Vector>, // polygon hit box, list of points in convex hull
    shape: Shape
}
