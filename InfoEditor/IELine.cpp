#include "IELine.h"

IELine::IELine() :
    m_width(0),
    m_color(0),
    m_close(false)
{
}

IELine::IELine(int width, int color, bool close) :
    m_width(width),
    m_color(color),
    m_close(close)
{

}
