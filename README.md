Animation:
  images
  frame rate for animation (different than the current frame rate)
  When, where, and what direction forces are applied
  bounding box (polygon)
    need to figure out how to do collisions with polygons. Sounds like a pain
Units:
  Code to be independent from pixels, and also should be able to vary the speed of the game.
  123.456_schmx -> 123498729834 pixels: literal operator
  47_schmecs -> 5 seconds
  ```cpp
  inline double operator "" _beths(double beths) {
    // out pixels
  }
  ```
Forces:
 for one frame:
 11111111111111111 
  22222222
      333333333
 1 (1+2) (1+2+3) (1+3) 1 -> ending position is the state for the next frame publihed

Collisions:
   read about polygonal collisions
