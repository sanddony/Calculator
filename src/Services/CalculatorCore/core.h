#ifndef SRC_SERVICES_CALCULATORCORE_CORE_H_
#define SRC_SERVICES_CALCULATORCORE_CORE_H_

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Interface for calculate expression
/// @param expression
/// @param validateStatus OK - 1; ERROR - 0
/// @param x
/// @return
double calculateExpression(const char* expression, int* validateStatus,
                           double x);

#ifdef __cplusplus
}
#endif

#endif  // SRC_SERVICES_CALCULATORCORE_CORE_H_