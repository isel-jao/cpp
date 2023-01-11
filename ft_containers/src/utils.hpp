#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
    template <
        class T1,
        class T2>
    struct pair
    {

    public:
    public:
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair(const first_type &first = first_type(), const second_type &second = second_type())
            : first(first), second(second) {}

        pair(const pair &pr)
            : first(pr.first), second(pr.second) {}

        pair &operator=(const pair &pr)
        {
            if (this == &pr)
                return (*this);
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }

        ~pair() {}
    };

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
}

template <class T1, class T2>
bool operator==(const ft::pair<const T1, const T2> &lhs, const ft::pair<const T1, const T2> &rhs)
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const ft::pair<const T1, const T2> &lhs, const ft::pair<const T1, const T2> &rhs)
{
    return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const ft::pair<const T1, const T2> &lhs, const ft::pair<const T1, const T2> &rhs)
{
    return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<=(const ft::pair<const T1, const T2> &lhs, const ft::pair<const T1, const T2> &rhs)
{
    return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const ft::pair<const T1, const T2> &lhs, const ft::pair<const T1, const T2> &rhs)
{
    return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const ft::pair<const T1, const T2> &lhs, const ft::pair<const T1, const T2> &rhs)
{
    return !(lhs < rhs);
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const ft::pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename container>
void print_container(const container &c)
{
    for (typename container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
template <typename container>
void print_container_reverse(const container &c)
{
    for (typename container::const_reverse_iterator it = c.rbegin(); it != c.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif