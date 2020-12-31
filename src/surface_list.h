#ifndef SURFACE_LIST_H
#define SURFACE_LIST_H

#include "surface.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class surface_list : public surface {
private:
    std::vector<shared_ptr<surface>> objects;
public:
    surface_list() = default;

    explicit surface_list(const shared_ptr<surface> &object) { add(object); }

    void clear() { objects.clear(); }

    void add(const shared_ptr<surface> &object) { objects.push_back(object); }

    bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

};

bool surface_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto &object: objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}


#endif //SURFACE_LIST_H
