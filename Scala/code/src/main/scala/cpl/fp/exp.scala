package cpl.fp

sealed trait Exp

object Exp {

  /**
    * Interpret 'exp' into an Int with a pattern match
    */
  def eval(exp: Exp): Int = ???

}

// Create two case classes, literal and addition. A literal contains
// an integer it represents and addition contains two expressions.
