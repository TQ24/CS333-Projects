# CS333
# Project 7
# EXTENSIONS
# Ruby
# Functionally equivalent function in C

# Ruby function
def func
  local = "hello"
  @intstance = "world"
end

# functionally equivalent C function
void func(){
  char *stack = "hello";
  char *heap = malloc(6);
  strncpy(heap, "world", 5);
  free(heap);
}
