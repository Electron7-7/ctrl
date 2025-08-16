#ifndef SAFE_RETURN_H
#define SAFE_RETURN_H

typedef unsigned short StatusID; // Change this if you really need more than 65535 unique statuses...

struct SafeStatus
{
public:
    SafeStatus(): _status(0), _printout("NO_ERROR") {}
    SafeStatus(const SafeStatus& CopyFrom): _status(CopyFrom._status), _printout(CopyFrom._printout) {}

    const StatusID ID() const { return _status; }
    const char* Printout() const { return _printout; }

    constexpr bool operator==(const SafeStatus& CompareTo) const { return (_status == CompareTo._status); }
    constexpr bool operator!=(const SafeStatus& CompareTo) const { return (_status != CompareTo._status); }
    constexpr bool operator< (const SafeStatus& CompareTo) const { return (_status <  CompareTo._status); }
    constexpr bool operator> (const SafeStatus& CompareTo) const { return (_status >  CompareTo._status); }
    constexpr bool operator<=(const SafeStatus& CompareTo) const { return (_status <= CompareTo._status); }
    constexpr bool operator>=(const SafeStatus& CompareTo) const { return (_status >= CompareTo._status); }

    constexpr operator StatusID() const { return _status; }

private:
    StatusID _status = 0;
    const char* _printout  = "You shouldn't be seeing this!";

    friend struct Status;
    constexpr SafeStatus(const StatusID Status, const char* Printout): _status(Status), _printout(Printout) {}
};

struct Status
{
    inline static SafeStatus NO_ERROR      = SafeStatus( 0b0, "NO_ERROR"      );
    inline static SafeStatus ERROR_GENERIC = SafeStatus( 0b1, "ERROR_GENERIC" );
};

template<typename T>
struct SafeReturn
{
public:
    SafeReturn(T Data, SafeStatus ReturnStatus = Status::NO_ERROR)
    :_data(Data), _status(ReturnStatus)
    {}

    const T& Data() const { return _data; }
    SafeStatus Status() const { return _status; }

private:
    T _data;
    SafeStatus _status = Status::NO_ERROR;
};

#endif // SAFE_RETURN_H
