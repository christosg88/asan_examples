class Parent {
public:
  int field;
};

class Child : public Parent {
public:
  int extra_field;
};

int main() {
  Parent *p = new Parent;
  Child *c = (Child *)p; // error: improper down-cast
  c->extra_field = 42;
  delete p;

  return 0;
}
