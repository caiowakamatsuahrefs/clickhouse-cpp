#pragma once

#include "clickhouse/columns/numeric.h"

#include <ctime>

namespace clickhouse {

/** */
class ColumnDate : public Column {
public:
    ColumnDate();

    /// Appends one element to the end of column.
    void Append(const std::time_t& value);

    /// Returns element at given row number.
    std::time_t At(size_t n) const;

public:
    /// Appends content of given column to the end of current one.
    void Append(ColumnRef column) override;

    /// Loads column data from input stream.
    bool Load(CodedInputStream* input, size_t rows) override;

    /// Saves column data to output stream.
    void Save(CodedOutputStream* output) override;

    /// Returns count of rows in the column.
    size_t Size() const override;

    /// Makes slice of the current column.
    ColumnRef Slice(size_t begin, size_t len) override;

private:
    std::shared_ptr<ColumnUInt16> data_;
};

/** */
class ColumnDateTime : public ColumnVector<uint32_t> {
public:
    ColumnDateTime() {
        type_ = Type::CreateDateTime();
    }

    /// Appends content of given column to the end of current one.
    void Append(ColumnRef) override { }

    ColumnRef Slice(size_t, size_t) override { return ColumnRef(); }
};

}