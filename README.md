# Code That I Reuse a Lot
Some code that I reuse a lot.

## Index (Categorized by Language)
- **[C++23](#c23)**
  - [printing.hpp](#printinghpp) - Custom printout macros for stylized "error", "warning", and "debug" messages
  - [colors.hpp](#colorshpp) - Useful namespace-like structs containing hard-coded ANSI color codes
  - [safe_return.hpp](#safe_returnhpp) - `SafeReturn` and `SafeStatus` are a lightweight way of returning both an object *and* a status message from any function

# C++23
## printing.hpp
This header file gives you three handy macros for printing labelled messages to the console.

Here are some examples of the macros in use:
```C++
// The macros in use:
PRINT_ERROR("You need to run this program as root (trust me, bro)!")
PRINT_WARNING("Looks like you forgot to escape some whitespace in your commandline argument! Don't worry, I'll push through it and fuck up your filesystem :D")
PRINT_DEBUG("crashfucktest34")
// Oh, yeah, all these macros support format strings, since they're just a wrapper around `std::print`
PRINT_DEBUG("line {} is not the crash", 19)
```

And here's what all of that looks like when printed to the console:
<details>
  <summary>Light Color Scheme</summary>
  <img width="1374" height="85" alt="08-15-2025_21:59:57_Selection_001" src="https://github.com/user-attachments/assets/13101e87-b03f-489f-8b3a-8528d363ae52" />
</details>
<details>
  <summary>Dark Color Scheme</summary>
  <img width="1376" height="85" alt="08-15-2025_22:00:54_Selection_001" src="https://github.com/user-attachments/assets/3f74e8f4-7b27-41a3-8afa-828c2d2243ed" />
</details>

## colors.hpp
This header file provides useful namespace-like structs that contain hardcoded ANSI color codes; `Color` is the parent struct, containing the ANSI code which resets all text back to normal and two sub-structs. These structs hold the ANSI codes for foreground (`Front`) and background (`Back`) colors, in both bold and normal weights. It's not very modular and it's pretty hardcoded, but I think that makes it more direct and easier to use.

As a bonus, all the colors use `constexpr const char*`, requiring no extra headers to be included!

## safe_return.hpp
`SafeReturn` and `SafeStatus` are my solutions to not being able to return an object *and* a status message at the same time. They're fairly high level, yes, but they *should* also be fairly lightweight. `SafeStatus` is just a wrapper for an unsigned short and a string, the short being the status' ID and the string being its name (useful for things like printouts). The `Status` struct acts like a namespace and is where you can define your custom `SafeStatus` objects. If you notice the two I've included, 'NO_ERROR' and 'ERROR_GENERIC', they're bitmasked; this means you can combine/compare statuses with bit operators (`|`, `|=`, `&`, `&=`, etc), which makes them double as bit flags/masks if needed. If you rack up a tremendous number of status messages and need more than an unsigned short can contain (that's 65535 unique statuses!), you can easily do so via the `StatusID` typedef that I've included at the top of the header file.

Here's an example of how you could use `SafeReturn` and `SafeStatus`:
```C++
SafeReturn<int> some_int = try_GetInt();

if(some_int.Status() != Status::NO_ERROR)
{
  std::print("Uhoh, looks like you got an error: '{}'\n", some_int.Status().Printout());
  return 1;
}
```
