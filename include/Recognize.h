#ifndef _RECOGNIZE_H_
#define _RECOGNIZE_H_

/**
 * Interface for digit recognizing algorithms.
 * @author EUYUIL
 * @date 2012-06-21
 */


/**
 * Learn the pattern.
 * @param r The result that the pattern should lead to.
 * @param c The pattern matrix.
 * @param w The width of the matrix.
 * @param h The height of the matrix.
 * @return True if learning was succeessful. False otherwise.
 * @author EUYUIL
 * @date 2012-06-21
 */

bool LearnPattern(char r, const char *c, unsigned int w, unsigned int h);


/**
 * Recognize the pattern.
 * @param c The pattern matrix.
 * @param w The width of the matrix.
 * @param h The height of the matrix.
 * @return The recognized character of the pattern.
 * @author EUYUIL
 * @date 2012-06-21
 */

char Recognize(const char *c, unsigned int w, unsigned int h);


/**
 * Save learning data into default destination.
 * @return True if succeeded. False otherwise.
 * @author EUYUIL
 * @date 2012-06-21
 */

bool SaveLearning();


/**
 * Load learning data from default destination.
 * @return True if succeeded. False otherwise.
 * @author EUYUIL
 * @date 2012-06-21
 */

bool LoadLearning();


#endif /* _RECOGNIZE_H_ */
