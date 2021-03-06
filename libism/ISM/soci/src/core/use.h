//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SOCI_USE_H_INCLUDED
#define SOCI_USE_H_INCLUDED

#include "soci-backend.h"

namespace soci
{

namespace details
{
template <typename T, typename Indicator>
struct use_container
{
    use_container(T &_t, Indicator &_ind, const std::string &_name)
        : t(_t), ind(_ind), name(_name) {}

    T &t;
    Indicator &ind;
    const std::string &name;
};

typedef void no_indicator;
template <typename T>
struct use_container<T, no_indicator>
{
    use_container(T &_t, const std::string &_name)
        : t(_t), name(_name) {}

    T &t;
    const std::string &name;
};

} // namespace details

template <typename T>
details::use_container<T, details::no_indicator> use(T &t, const std::string &name = std::string())
{ return details::use_container<T, details::no_indicator>(t, name); }

template <typename T>
details::use_container<const T, details::no_indicator> use(T const &t, const std::string &name = std::string())
{ return details::use_container<const T, details::no_indicator>(t, name); }

template <typename T>
details::use_container<T, indicator> use(T &t, indicator & ind, std::string const &name = std::string())
{ return details::use_container<T, indicator>(t, ind, name); }

template <typename T>
details::use_container<const T, indicator> use(T const &t, indicator & ind, std::string const &name = std::string())
{ return details::use_container<const T, indicator>(t, ind, name); }

// vector containers
template <typename T>
details::use_container<T, std::vector<indicator> > 
    use(T &t, std::vector<indicator> & ind, const std::string &name = std::string())
{ return details::use_container<T, std::vector<indicator> >(t, ind, name); }

template <typename T>
details::use_container<std::vector<T>, details::no_indicator > 
    use(std::vector<T> &t, const std::string &name = std::string())
{ return details::use_container<std::vector<T>, details::no_indicator>(t, name); }

} // namespace soci

#endif // SOCI_USE_H_INCLUDED
