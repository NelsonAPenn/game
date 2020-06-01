# Game

## Workflow

- All code should be written on local branches branched from `dev`. These local branches should each fix one specific problem, to prevent later hell.

- Pull requests should be made from local branches into `dev` to be looked over by someone else. Code should be made as clean as possible here.

- Every once in a while, pull requests should be made from `dev` into `uat`. This is the branch from which we have others test our game.

- Once we are confident about the quality of code in `uat` we make a pull request from `uat` into `prod`. This should be reviewed by each developer.

## Running

Need to have `SFML` installed.

Run
```bash
make
./build/game # for optimized version
./build/dbggame # for unoptimized debug/GDB version
```

