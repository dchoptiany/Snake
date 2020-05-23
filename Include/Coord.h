struct Coord
{
    Coord(unsigned x, unsigned y)
            :x(x), y(y)
    {
    }

    unsigned x;
    unsigned y;

    bool operator==(const Coord& rhs) const
    {
        return (x == rhs.x) && (y == rhs.y);
    }
};
