/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:58:53 by isel-jao          #+#    #+#             */
/*   Updated: 2023/01/14 09:45:36 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        template <class U1, class U2>
        pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

        pair &operator=(const pair &pr)
        {
            if (this == &pr)
                return (*this);
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }

        ~pair() {}

        
        friend bool operator==(const pair &lhs, const pair &rhs)
        {
            return (lhs.first == rhs.first && lhs.second == rhs.second);
        }

        
        friend bool operator!=(const pair &lhs, const pair &rhs)
        {
            return !(lhs == rhs);
        }

        
        friend bool operator<(const pair &lhs, const pair &rhs)
        {
            return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
        }

        
        friend bool operator<=(const pair &lhs, const pair &rhs)
        {
            return !(rhs < lhs);
        }

        
        friend bool operator>(const pair &lhs, const pair &rhs)
        {
            return (rhs < lhs);
        }

        
        friend bool operator>=(const pair &lhs, const pair &rhs)
        {
            return !(lhs < rhs);
        }
    };


        
    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
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
void print_container(const container &c, const char *name = NULL, const char *sep = " ", const char *end = "\n")
{
    if (name)
        std::cout << name << ": ";
    for (typename container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << sep;
    std::cout << end << std::flush;
}

namespace ft
{

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }
}

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

#endif