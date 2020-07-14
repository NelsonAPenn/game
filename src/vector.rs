#![allow(dead_code)]
use std::ops;
use std::f64::consts;

#[derive(Debug)]
pub enum Coords
{
    Cartesian { x: f64, y: f64 },
    Polar { magnitude: f64, direction: f64 }
}

impl Coords
{
    pub fn convert(&self) -> Coords
    {
        match self
        {
            Coords::Cartesian { x, y } => {
                Coords::Polar { magnitude: x.hypot(*y), direction: y.atan2(*x) }
            },
            Coords::Polar { magnitude, direction } => {
                assert!(magnitude >= &0.0);
                Coords::Cartesian { x: magnitude * direction.cos(), y: magnitude * direction.sin() }
            }

        }

    }
}

impl From<Vector> for Coords
{
    fn from(v: Vector) -> Coords
    {
        return Coords::Cartesian { x: v.x, y: v.y };
    }
}

#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Vector
{
    x: f64,
    y: f64
}

impl Vector
{
    const ONES: Vector = Vector { x: 1.0, y: 1.0 };
    const ZEROS: Vector = Vector { x: 0.0, y: 0.0 };
    #[allow(non_upper_case_globals)]
    const i: Vector = Vector { x: 1.0, y: 0.0 };
    #[allow(non_upper_case_globals)]
    const j: Vector = Vector { x: 0.0, y: 1.0 };

    pub fn reflect_across(&mut self, other: Vector)
    {
        let (m1, d1) = match Coords::from(self.clone()).convert()
        {
            Coords::Polar { magnitude, direction } => (magnitude, direction),
            _ => { panic!("Ain't polar!"); }
        };
        let d2 = match Coords::from(other).convert()
        {
            Coords::Polar { magnitude: _, direction } => direction,
            _ => { panic!("Ain't polar!"); }
        };
        
        match (Coords::Polar { magnitude: m1, direction: (2.0 * d2 - d1) % (2.0 * consts::PI) }).convert()
        {
            Coords::Cartesian { x, y } => {
                self.x = x;
                self.y = y;
            },
            _ => panic!("Ain't cartesian")
        };

    }
}

impl From<Coords> for Vector
{
    fn from(coords: Coords) -> Vector
    {
        match coords
        {
            Coords::Cartesian { x, y } => Vector { x: x, y: y },
            Coords::Polar { magnitude: _, direction: _ } => {
                let cart = coords.convert();
                match cart
                {
                    Coords::Cartesian { x, y } => Vector { x: x, y: y },
                    _ => { panic!("ain't cartesian"); }
                }
            }

        }
    }
}

impl ops::Add<Vector> for Vector
{
    type Output = Vector;
    fn add(self, rhs: Vector) -> Self::Output
    {
        Vector { x: self.x + rhs.x, y: self.y + rhs.y }
    }
}

impl ops::Sub<Vector> for Vector
{
    type Output = Vector;
    fn sub(self, rhs: Vector) -> Self::Output
    {
        Vector { x: self.x - rhs.x, y: self.y - rhs.y }
    }
}

impl ops::AddAssign<Vector> for Vector
{
    fn add_assign(&mut self, rhs: Vector)
    {
        self.x = self.x + rhs.x;
        self.y = self.y + rhs.y;
    }
}

impl ops::SubAssign<Vector> for Vector
{
    fn sub_assign(&mut self, rhs: Vector)
    {
        self.x = self.x - rhs.x;
        self.y = self.y - rhs.y;
    }
}

impl ops::Neg for Vector
{
    type Output = Vector;

    fn neg(self) -> Self::Output
    {
        Vector { x: -self.x, y: -self.y }
    }
}

impl ops::Mul<f64> for Vector
{
    type Output = Vector;
    fn mul(self, rhs: f64) -> Self::Output
    {
        Vector{ x: self.x * rhs, y: self.y * rhs }
    }
}

impl ops::Mul<Vector> for Vector // dot product
{
    type Output = f64;
    fn mul(self, rhs: Vector) -> Self::Output
    {
        self.x * rhs.x + self.y * rhs.y
    }
}

impl ops::MulAssign<f64> for Vector
{
    fn mul_assign(&mut self, rhs: f64)
    {
        self.x = self.x * rhs;
        self.y = self.y * rhs;
    }
}

impl ops::Div<f64> for Vector
{
    type Output = Vector;
    fn div(self, rhs: f64) -> Self::Output
    {
        assert!(rhs != 0.0);
        Vector{ x: self.x / rhs, y: self.y / rhs }
    }
}

impl ops::DivAssign<f64> for Vector
{
    fn div_assign(&mut self, rhs: f64)
    {
        assert!(rhs != 0.0);
        self.x = self.x / rhs;
        self.y = self.y / rhs;
    }
}

#[cfg(test)]
mod tests
{
    use super::*;

    #[test]
    fn test_add()
    {
        assert_eq!(Vector{x: 1.5, y: 2.5} + Vector::ONES.clone(), Vector{x: 2.5, y: 3.5});
    }

    #[test]
    fn test_dot()
    {
        assert!(Vector{ x: 1.5, y: 2.5 } * Vector{ x: 2.0, y: 2.0 } == 8.0);
    }

    #[test]
    fn test_reflect()
    {
        let mut to_reflect = Vector::from(Coords::Polar{ magnitude: 1.0, direction: -consts::PI / 4.0 });
        to_reflect.reflect_across( Vector { x: 1.0, y: 0.0 } );
        assert_eq!(to_reflect, Vector::from(Coords::Polar{ magnitude: 1.0, direction: consts::PI / 4.0 })); 
    }
}
