# Forbidden Upcasting

## Functionality

The child object `Auto` of superordinate class becomes a parent object by casting upwards. The reference to a derived class is converted into reference to the base class `Fahrzeug`.

> Type promotion can be disabled as following:

### Destuctor Protection

```
class Fahrzeug {
 protected:
  ~Fahrzeug() {}  // Protected destructor
};
```

### Full Destructor Declaration

```
class Fahrzeug {
 public:
  ~Fahrzeug() {}  // Non-virtual destructor
};
```
