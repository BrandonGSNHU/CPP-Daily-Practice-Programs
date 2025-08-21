/* NOTES:
*  // ctor / dtor short for constructor and deconstructor
* 
*  Lvalues vs rvalues:
* 
*  lvalue - "has a name / address " you might use it again
*  std::string s = "orc"; -> s is an lvalue
* 
*  rvalue - Temporary / about to disappear.
*  "orc", MakeName() return, or std::move(s).
*  Moves are allowed from rvalues. If you have an lvalue you're done with you can opt in to 
*  moving by writing std::move(s).
* 
*  std::move:
*  
*  std::move(x) does not move by itself - it casts x to an rvalue so move enabled operations will be
*  chosen. After moving from an object its valid but unspecified. Don't read its old contents reassign
*  or destroy it.
*  EX:
*  
*  // ctor: pass by value + move into member (handles both l and r values)
*  Player(std::string name) : name_(std::move(name)) {}
*  
*  // containers: avoid a copy when you're done with s
*  std::vectors<std::string> v;
*  std::string s = "Goblin";
*  v.push_back(std::move(s));
* 
*  Copy vs Move semantics (Rule of 0/3/5):
* 
*  Rule of 0 (preferred) - if your class only usees types that manage themselves
*  (std::string, std::vector, smart pointers) don't write any of dtor, copy / move ctor,
*  copy / move assign. 
*  
*  Rule of 5 - If you own a raw resource (new / delete, file handle, socket) provide all five
*  1. Destructor
*  2. Copy constructor
*  3. Copy assignment
*  4. Move constructor noexcept
*  5. Move assignment noexcept
*  EX:
* 
*  class Resource {
*  public: 
*		Resource();									 // Normal constructor
*	   ~Resource();									// Frees resource
*		Resource(const Resource&);				   // Deep-copy
*		Resource& operator=(const Resource&);	  // Copy  - assign ( copy swap is great)
*		Resource(Resource&&) noexcept;			 // Steal pointers / handles and null out source
*		Resource& operator=(Resource&&) noexcept; 
* };
* 
*  Why noexcept matters: 
* 
*  Containers like std::vector prefer move during reallocation only if the move constructor
*  is noexcept. If its not noexcept they may fall back to copy for strong exception safety. 
*  Guideline - If your move operations can't throw (stealing pointers, resetting counters) mark them noexcept.
* 
*  Parameter passing: which one to use?
* 
*  Small trivially copied types (ints, small POD) pass by value.
*  Read only possibly large: const T&
*  Sink parameter (you'll store it) pass by value and std::move into the member.
*  EX:
*  
*  Widget(std::string name) : name_(std::move(name)) {}
*  Forwarding to another constructor / factory use templates + T&& + std::forward<T>(t) (advanced later).
* 
*  Returns and RVO:
* 
*  * Elide = omit *
*  * Elision = the omission itself *
*  * When we say the copy was elided we mean the compiler didn't perform that copy / move at all.
* 
*  RVO - Return Value Optimization:
* 
*  The compiler constructs the functions return value directly in the callers storage
*  avoiding any copy / move.
*  Classic case (temporary / prvalue in the return):
* 
*  struct T { T(); T(const T&); T(T&&) noexcept; );
*  T make() {
*		return T():  // RVO object is built directly in the caller.
* 
*  Since C++17 this elision is mandatory in cases like the above( same type, returning a prvalue)
*  No copy / move constructor runs
* 
*  NRVO - Name Return Value Optimization:
* 
*  Same idea but with a named local
*  EX: 
* 
*  T make() {
*		T x;		// named local
*		// ... init x 
*		return x;	// NRVO: often elided but not guaranteed by the standard
* 
*  Compilers usually do NRVO but its not guaranteed in all control flows.
* 
*  ~ Why you shouldn't std:move the return local:
*  Writing return std::move(x); tells the compiler " I insist on moving" which can block
*  NRVO and force a move. EX:
* 
*  T make() {
*		T x;
*		return x;		// NRVO likely no copy / move
*		// Return std::move(x);		// X prevents NVRO does a move instead
* 
*  Quck Rules of Thumbe:
*  C++17 return T(); or return makeT(); -> guaranteed copy elision (no copy / moves)
*  Return local; -> NRVO usually happens dont add std::move(local)
*  Only std::move on return when you're returning a member or subobject you can't elide (rare) or
*  when elision cant apply and you truly want a move.
*  Prefer:
*  
*  std::string MakeName()
* {
*	std::string s = "Orc";
*	return s:	// NRVO/RVO usually elides copies / moves
* 
*  Don't do return std::move(s); it can block NRVO and force a move
* 
*  Smart Pointers (ownership in one line):
*  
*  std::unique_ptr<T>: exclusive ownership move only
*  EX: 
*  
*  auto p = std::make_unique<Foo>():
*  take(std::move(p)); // Transfer ownership
* 
*  std::shared_ptr<T>: shared lifetime via reference counting. Use sparingly.
*  Use raw pointers or references to express non owning relationships
* 
*  Containers and moves (performance tips):
*  
*  Reserve when you know rougly how many elements you'll push.
*  Prefer emplace_back(args...) to construct in place (avoids temporary)
*  When pushing an existing variable you won't use after: push_back(std::move(x))
*  Moves during reallocation require noexcept move to be chosen reliably
* 
*  Common pitfalls (MEMORIZE)
*  
*  Moving from const T performs a copy (moves can't "Steal" from const)
*  Don't use moved from objects except to reassessing / destroy
*  Don't std::move on return let RVO work
*  If you implement any of the five special members for a resource owning type implement the set
*  coherently (rule of 5)
*/