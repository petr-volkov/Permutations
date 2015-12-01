//
// Created by petr_v on 25/11/2015.
//


#include <string>
#include <algorithm>
#include <stdexcept>
#include "bed_entry.h"
#include "genome_info.h"

BedEntry::BedEntry(std::string chr, long int start, long int end) : chr(chr), start(start), end(end) {
    if(GenomeInfo::chrInfo.find(chr) == GenomeInfo::chrInfo.end()) {
        //if(std::find(GenomeInfo::acceptedChrList.begin(), GenomeInfo::acceptedChrList.end(), chr) == GenomeInfo::acceptedChrList.end()) {
        throw std::invalid_argument("Wrong chromosome!");
    }
    if(start < 0 || end < 0) {
        throw std::invalid_argument("Negative locations!");
    }
    if(start > end) {
        throw std::invalid_argument("Start is greater then end!");
    }
}


long int BedEntry::getStart() const {
    return start;
}

long int BedEntry::getEnd() const {
    return end;
}

std::string BedEntry::getChr() const {
    return chr;
}

long BedEntry::intersect(BedEntry anotherEntry) {
    if (this->chr != anotherEntry.chr) {
        return 0;
    }
    if (this->start > anotherEntry.end) {
        return 0;
    }
    if (this->end < anotherEntry.start) {
        return 0;
    }
    if (this->start >= anotherEntry.start && this->end >= anotherEntry.end) { //in case if this (x1, x2) overlaps another (y1, y2) from the right: (y1, x1, y2, x2)
        return anotherEntry.end - this->start + 1;
    }
    if (this->start <= anotherEntry.start && this->end <= anotherEntry.end) { //in case if this (x1, x2) overlaps another (y1, y2) from the left: (x1, y1, x2, y2)
        return this->end - anotherEntry.start + 1;
    }
    if (this->start >= anotherEntry.start && this->end <= anotherEntry.end) { //in case if this (x1, x2) is inside another (y1, y2) (y1, x1, x2, y2)
        return this->end - this->start + 1;
    }
    if (this->start <= anotherEntry.start && this->end >= anotherEntry.end) { //in case if this (x1, x2) is outside another (y1, y2) (x1, y1, y2, x2)
        return anotherEntry.end - anotherEntry.start + 1;
    }
    return 0;
}

std::ostream& operator<< (std::ostream &out, BedEntry &entry) {
    out << entry.chr << '\t' << entry.getStart() << '\t' << entry.getEnd();
    return out;
}

bool operator<(const BedEntry &first, const BedEntry &second) {
    return first.start < second.start;
}

bool operator>(const BedEntry &first, const BedEntry &second) {
    return first.start > second.start;
}

bool operator==(const BedEntry &first, const BedEntry &second) {
    return first.chr == second.chr && first.start == second.start && first.end == second.end;
}

bool operator!=(const BedEntry &first, const BedEntry &second) {
    return !(first == second);
}

void BedEntry::setChr(std::string newChr) {
    chr = newChr;
}
