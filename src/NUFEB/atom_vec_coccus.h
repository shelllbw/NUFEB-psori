/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef ATOM_CLASS

AtomStyle(coccus,AtomVecCoccus)

#else

#ifndef LMP_ATOM_VEC_COCCUS_H
#define LMP_ATOM_VEC_COCCUS_H

#include "atom_vec.h"

namespace LAMMPS_NS {

class AtomVecCoccus : public AtomVec {
 public:
  AtomVecCoccus(class LAMMPS *);
  void process_args(int, char **);
  void init();

  void grow_pointers();
  void create_atom_post(int);
  void data_atom_post(int);
  void pack_data_pre(int);
  void pack_data_post(int);

 private:
  double *radius,*rmass;
  double **omega;
  double *biomass,*outer_radius,*outer_mass;

  int radvary;
  double radius_one,rmass_one;
  double outer_radius_one;
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Per-processor system is too big

The number of owned atoms plus ghost atoms on a single
processor must fit in 32-bit integer.

E: Invalid atom type in Atoms section of data file

Atom types must range from 1 to specified # of types.

E: Invalid radius in Atoms section of data file

Radius must be >= 0.0.

E: Invalid density in Atoms section of data file

Density value cannot be <= 0.0.

*/
