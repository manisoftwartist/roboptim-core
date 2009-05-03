// Copyright (C) 2009 by Thomas Moulard, AIST, CNRS, INRIA.
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

/**
 * \brief Declaration of the QuadraticFunction class.
 */

#ifndef ROBOPTIM_CORE_QUADRATIC_FUNCTION_HH
# define ROBOPTIM_CORE_QUADRATIC_FUNCTION_HH
# include <limits>

# include <roboptim/core/twice-derivable-function.hh>

namespace roboptim
{
  /**
     \addtogroup roboptim_function
     @{
  */

  /// Define a quadratic function.
  class QuadraticFunction : public TwiceDerivableFunction
  {
  public:
    QuadraticFunction (size_type n, size_type m = 1) throw ();

    virtual std::ostream& print (std::ostream&) const throw ();
  };
  /**
     @}
  */
} // end of namespace roboptim
#endif //! ROBOPTIM_CORE_QUADRATIC_FUNCTION_HH