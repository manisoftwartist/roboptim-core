// Copyright (C) 2013 by Thomas Moulard, AIST, CNRS, INRIA.
//
// This file is part of the roboptim.
//
// roboptim is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// roboptim is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with roboptim.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROBOPTIM_CORE_FILTER_SCALAR_HH
# define ROBOPTIM_CORE_FILTER_SCALAR_HH
# include <vector>
# include <boost/shared_ptr.hpp>

# include <roboptim/core/detail/autopromote.hh>
# include <roboptim/core/differentiable-function.hh>


namespace roboptim
{
  /// \brief Select part of a function.
  template <typename U>
  class Scalar : public detail::AutopromoteTrait<U>::T_type
  {
  public:
    typedef typename detail::AutopromoteTrait<U>::T_type parentType_t;
    ROBOPTIM_DIFFERENTIABLE_FUNCTION_FWD_TYPEDEFS_ (parentType_t);

    typedef boost::shared_ptr<Scalar> ScalarShPtr_t;

    explicit Scalar (boost::shared_ptr<U> left,
		     value_type scalar) throw ();
    ~Scalar () throw ();

    const boost::shared_ptr<U>& origin () const
    {
      return origin_;
    }

    boost::shared_ptr<U>& origin ()
    {
      return origin_;
    }

    void impl_compute (result_t& result, const argument_t& x)
      const throw ();

    void impl_gradient (gradient_t& gradient,
			const argument_t& argument,
			size_type functionId = 0)
      const throw ();
    void impl_jacobian (jacobian_t& jacobian,
			const argument_t& arg)
      const throw ();
  private:
    boost::shared_ptr<U> origin_;

    value_type scalar_;
  };

  template <typename U>
  boost::shared_ptr<Scalar<U> >
  scalar (boost::shared_ptr<U> origin,
	  typename Scalar<U>::size_type start = 0,
	  typename Scalar<U>::size_type size = 1)
  {
    return boost::make_shared<Scalar<U> > (origin, start, size);
  }

  template <typename U>
  boost::shared_ptr<Scalar<U> >
  operator* (typename Scalar<U>::value_type scalar,
	     boost::shared_ptr<U> origin)
  {
    return boost::make_shared<Scalar<U> > (origin, scalar);
  }

  template <typename U>
  boost::shared_ptr<Scalar<U> >
  operator* (boost::shared_ptr<U> origin,
	     typename Scalar<U>::value_type scalar)
  {
    return boost::make_shared<Scalar<U> > (origin, scalar);
  }

  template <typename U>
  boost::shared_ptr<U>
  operator+ (boost::shared_ptr<U> origin)
  {
    return origin;
  }

  template <typename U>
  boost::shared_ptr<Scalar<U> >
  operator- (boost::shared_ptr<U> origin)
  {
    return boost::make_shared<Scalar<U> > (origin, -1.);
  }


} // end of namespace roboptim.

# include <roboptim/core/filter/scalar.hxx>
#endif //! ROBOPTIM_CORE_FILTER_SCALAR_HH
