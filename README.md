# Buddhabrot
Buddhabrot is a fractal shape representing the trajectories of points that escape the most famous fractal in the world, the Mandelbrot. Without getting too deeply inside the math the fractal is drawn by randomly selecting numbers in the complex plane, for each of these we calculate a bunch of values of the sequence:
![alt text](https://wikimedia.org/api/rest_v1/media/math/render/svg/1a54e8358cb6b679f0936e282906d718bd34ecb3)
Each time we compute a new value of Zn we increase the brigthness of the corrisponding pixel on the screen.

The code is pretty old and terrible and for some reason I decided to output the image as a ppm, so you will need to process it with ps/gimp, but from this simple code the resoults are pretty amazing, here are some:

![alt text](https://i.imgur.com/mK7CkOr.jpg)

I'm planning to update this project using GPU accelleration!
