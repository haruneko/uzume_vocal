// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include <algorithm>
#include "Expression.hpp"

using namespace uzume::vocal;

Expression::Expression() : events() {
    events.push_back(ExpressionEvent{0.0, 1.0});
}

Expression::Expression(std::vector<ExpressionEvent> events) : events(events) {
    if (events.empty()) {
        events.push_back(ExpressionEvent{0.0, 1.0});
    }
}

void Expression::insert(double position, double value) {
    auto i = std::find_if(events.begin(), events.end(),
                          [position](const ExpressionEvent &e) { return position <= e.position; });
    if (i == events.end()) {
        events.emplace_back(ExpressionEvent{position, value});
    } else {
        if (i->position == position) {
            i->value = value;
        } else {
            events.emplace(i, ExpressionEvent{position, value});
        }
    }
}

void Expression::deleteBetween(double begin, double end) {
    auto result = std::remove_if(events.begin(), events.end(), [begin, end](const ExpressionEvent &e) {
        return begin <= e.position && e.position <= end;
    });
    events.erase(result, events.end());
    if (events.empty()) {
        events.push_back(ExpressionEvent{0.0, 1.0});
    }
}

double Expression::at(double position) const {
    auto i(std::find_if(events.begin(), events.end(),
                        [position](const ExpressionEvent &e) { return e.position > position; }));
    if (i == events.begin()) {
        return i->value;
    } else if (i == events.end()) {
        return (i - 1)->value;
    } else {
        auto prev = i - 1;
        double ratio = (position - prev->position) / (i->position - prev->position);
        return prev->value * (1 - ratio) + i->value * ratio;
    }
}

std::string Expression::toString() const {
    std::string values;
    for(const auto &e: events) {
        values +="(" + std::to_string(e.position) + "," + std::to_string(e.value) + "),";
    }
    return "uzume::vocal::Expression(" + values + ")";
}
