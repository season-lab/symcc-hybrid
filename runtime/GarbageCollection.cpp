// This file is part of SymCC.
//
// SymCC is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// SymCC is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// SymCC. If not, see <https://www.gnu.org/licenses/>.

#include "GarbageCollection.h"

#include <vector>

#include <Runtime.h>

#if 0
#include <Shadow.h>
#endif

/// A list of memory regions that are known to contain symbolic expressions.
std::vector<ExpressionRegion> expressionRegions;

void registerExpressionRegion(ExpressionRegion r) {
  expressionRegions.push_back(std::move(r));
}

std::set<SymExpr> collectReachableExpressions() {
  abort(); // FIXME

  std::set<SymExpr> reachableExpressions;
  auto collectReachableExpressions = [&](ExpressionRegion r) {
    auto *end = r.first + r.second;
    for (SymExpr *expr_ptr = r.first; expr_ptr < end; expr_ptr++) {
      if (*expr_ptr != nullptr) {
        reachableExpressions.insert(*expr_ptr);
      }
    }
  };

  for (auto &r : expressionRegions) {
    collectReachableExpressions(r);
  }
#if 0 // FIXME
  for (const auto &mapping : g_shadow_pages) {
    collectReachableExpressions({mapping.second, kPageSize});
  }
#endif
  return reachableExpressions;
}
