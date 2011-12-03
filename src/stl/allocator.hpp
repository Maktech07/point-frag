// ======================================================================== //
// Directly taken and adapted from RDESTL                                   //
// http://code.google.com/p/rdestl/                                         //
// ======================================================================== //

#ifndef __PF_STL_ALLOCATOR_HPP__
#define __PF_STL_ALLOCATOR_HPP__

namespace pf
{
  /*! CONCEPT */
  class allocator
  {
  public:
    explicit allocator(const char* name = "DEFAULT"):  m_name(name) {}
    // Copy ctor generated by compiler.
    // allocator(const allocator&)
    ~allocator() {}

    // Generated by compiler.
    //allocator& operator=(const allocator&)

    void* allocate(unsigned int bytes, int flags = 0);
    // Not supported for standard allocator for the time being.
    void* allocate_aligned(unsigned int bytes, unsigned int alignment, int flags = 0);
    void deallocate(void* ptr, unsigned int bytes);

    const char* get_name() const;

  private:
    const char*  m_name;
  };

  // True if lhs can free memory allocated by rhs and vice-versa.
  inline bool operator==(const allocator& /*lhs*/, const allocator& /*rhs*/) { return true; }
  inline bool operator!=(const allocator& lhs, const allocator& rhs) { return !(lhs == rhs); }
  inline void* allocator::allocate(unsigned int bytes, int) { return operator new(bytes); }
  inline void allocator::deallocate(void* ptr, unsigned int) { operator delete(ptr); }

} // namespace pf

#endif /* __PF_STL_ALLOCATOR_HPP__ */

