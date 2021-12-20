#include <string>
#include <vector>

class Window_mgr;

class Screen{
  using pos = std::string::size_type;
  public:
    Screen() = default;
    Screen(pos ht, pos wd, char c=' '):
      height(ht), width(wd), contents(ht*wd, c) { }

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c); // move cursor to (r,c)

    Screen &set(char);  // set element pointed by cursor
    Screen &set(pos, pos, char);  // set element at (x,y)

    void func() const { ++access_str; }

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_str;
      // able to be changed even inside const function

  //friend void Window_mgr::clear(ScreenIndex);
  friend Window_mgr;
};

char Screen::get(pos r, pos c) const {
  return contents[r*width + c];
}

inline Screen &Screen::move(pos r, pos c){
  cursor = r * width + c;
  return *this;
}

inline Screen &Screen::set(char ch){
  contents[cursor] = ch;
  return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch){
  contents[r*width + c] = ch;
  return *this;
}

class Window_mgr{
  using ScreenIndex = std::vector<Screen>::size_type;
  public:
    void clear(ScreenIndex);
  private:
    std::vector<Screen> screens{ Screen(24, 80, ' ') };
};


void Window_mgr::clear(ScreenIndex i){
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}
