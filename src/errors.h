/* 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */

/* 
 * File:   errors.h
 * Author: Peter G. Jensen <root@petergjoel.dk>
 *
 * Created on May 10, 2019, 9:46 AM
 */

#ifndef ERRORS_H
#define ERRORS_H

struct base_error : public std::exception {
    std::string _message;

    explicit base_error(std::string m)
    : _message(std::move(m)) {
    }

    const char *what() const noexcept override {
        return _message.c_str();
    }

    virtual void print(std::ostream &os) const {
        os << what() << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const base_error &el) {
        el.print(os);
        return os;
    }
};

#endif /* ERRORS_H */

