#include "ScrollableFactory.h"
vector<Scrollable> ScrollableFactory::fromString(string _text)
{

  vector<Scrollable> scrollables;

  for(char& c : _text)
  {
    scrollables.push_back(getScrollable(c));
  }

  return scrollables;
}

Scrollable ScrollableFactory::getScrollable(const char _char)
{
  Scrollable scrollable;

  switch (_char) {
    case 'A': case 'a':
    {
      int pattern[] = {
        0,0,0,
        0,1,0,
        1,0,1,
        1,1,1,
        1,0,1,
        1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'B': case 'b':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        1,0,1,
        1,1,0,
        1,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'C': case 'c':
    {
      int pattern[] = {
        0,0,0,
        0,1,1,
        1,0,0,
        1,0,0,
        1,0,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'D': case 'd':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        1,0,1,
        1,0,1,
        1,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'E': case 'e':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        1,0,0,
        1,1,0,
        1,0,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'F': case 'f':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        1,0,0,
        1,1,0,
        1,0,0,
        1,0,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'G': case 'g':
    {
      int pattern[] = {
        0,0,0,
        0,1,1,
        1,0,0,
        1,0,1,
        1,0,1,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'H': case 'h':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        1,1,1,
        1,0,1,
        1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'I': case 'i':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        0,1,0,
        0,1,0,
        0,1,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'J': case 'j':
    {
      int pattern[] = {
        0,0,0,
        0,0,1,
        0,0,1,
        0,0,1,
        0,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'K': case 'k':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        1,1,0,
        1,0,1,
        1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'L': case 'l':
    {
      int pattern[] = {
        0,0,0,
        1,0,0,
        1,0,0,
        1,0,0,
        1,0,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'M': case 'm':
    {
      int pattern[] = {
        0,0,0,0,0,
        1,1,0,1,0,
        1,0,1,0,1,
        1,0,1,0,1,
        1,0,1,0,1,
        1,0,1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'N': case 'n':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        1,0,1,
        1,0,1,
        1,0,1,
        1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'O': case 'o': case '0':
    {
      int pattern[] = {
        0,0,0,
        0,1,0,
        1,0,1,
        1,0,1,
        1,0,1,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'P': case 'p':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        1,0,1,
        1,1,0,
        1,0,0,
        1,0,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'Q': case 'q':
    {
      int pattern[] = {
        0,0,0,
        0,1,0,
        1,0,1,
        1,0,1,
        1,0,1,
        0,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'R': case 'r':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        1,0,1,
        1,1,0,
        1,0,1,
        1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'S': case 's':
    {
      int pattern[] = {
        0,0,0,
        0,1,1,
        1,0,0,
        0,1,0,
        0,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'T': case 't':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        0,1,0,
        0,1,0,
        0,1,0,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'U': case 'u':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        1,0,1,
        1,0,1,
        0,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'V': case 'v':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        1,0,1,
        1,0,1,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'W': case 'w':
    {
      int pattern[] = {
        0,0,0,0,0,
        1,0,1,0,1,
        1,0,1,0,1,
        1,0,1,0,1,
        1,0,1,0,1,
        0,1,0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'X': case 'x':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        0,1,0,
        1,0,1,
        1,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'Y': case 'y':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        0,1,1,
        0,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case 'Z': case 'z':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        0,0,1,
        0,1,0,
        1,0,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '1':
    {
      int pattern[] = {
        0,0,0,
        0,1,0,
        1,1,0,
        0,1,0,
        0,1,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '2':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        0,0,1,
        0,1,0,
        1,0,0,
        1,1,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '3':
    {
      int pattern[] = {
        0,0,0,
        1,1,0,
        0,0,1,
        0,1,0,
        0,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '4':
    {
      int pattern[] = {
        0,0,0,
        1,0,1,
        1,0,1,
        1,1,1,
        0,0,1,
        0,0,1,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '5':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        1,0,0,
        0,1,0,
        0,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '6':
    {
      int pattern[] = {
        0,0,0,
        0,1,1,
        1,0,0,
        1,1,0,
        1,0,1,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '7':
    {
      int pattern[] = {
        0,0,0,
        1,1,1,
        0,0,1,
        0,1,0,
        0,1,0,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '8':
    {
      int pattern[] = {
        0,0,0,
        0,1,0,
        1,0,1,
        0,1,0,
        1,0,1,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    case '9':
    {
      int pattern[] = {
        0,0,0,
        0,1,0,
        1,0,1,
        0,1,1,
        0,0,1,
        1,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }

    default:
    {
      int pattern[] = {
        1,0,1,
        0,1,0,
        1,0,1,
        0,1,0,
        1,0,1,
        0,1,0,
      };
      scrollable.setPattern(pattern);
      break;
    }
  }
  return scrollable;
}
