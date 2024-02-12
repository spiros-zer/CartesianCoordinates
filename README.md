<header>
  <h2>CartesianCoordinates</h2>
  <p>Custom implementation of the Cartesian coordinates system in C++</p>
</header>

<div> 
  <h2>Functionality</h2>
  <p><strong>Current state</strong> supports only 2D axis through CartesianCoordinates2D; more specifically coordinates are displayed as (x, y) point.</p>
</div>

<h2>CartesianCoordinates2D</h2>
<p>Bellow is a list of the base functions of the library <strong>CartesianCoordinates2D.h</strong>. Implementation can be found in CartesianCoordinates2D.cpp</p>

```C++
struct CartesianCoordinates2D
```

<p>Constructors and Destructors</p>

```C++
CartesianCoordinates2D(double InX, double InY);
CartesianCoordinates2D();
```

<p>Operator Overloading</p>

```C++
CartesianCoordinates2D operator+(const CartesianCoordinates2D& Point) const;
CartesianCoordinates2D operator-(const CartesianCoordinates2D& Point) const;
CartesianCoordinates2D operator*(double Num) const;
```

<p>Other functions</p>

```C++
/** @brief Converts cartesian coordinate to char*. */
char* ToString(int& InSize, int Precision = 2) const;

/** @brief Prints the Cstring in the iostream with the NULL char. */
void Print() const;
```

<footer>
  <h2>Dependencies</h2>
  <p>This library uses the <a href="https://github.com/spiros-zer/Converters">Converters</a> library to convert the double to a char*. A <em>testbed</em> is offered where the capabilities of the CartesianCoordinates2D library can be tested in the <a href="https://github.com/spiros-zer/Testbed">Testbed</a> repository. </p>
</footer>
