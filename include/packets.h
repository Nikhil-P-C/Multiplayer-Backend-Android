struct PlayerBuffer {
    uint32_t playerId;
    uint32_t health;
    uint32_t x;
    uint32_t y;
    char color = 'u';// u for undefined, r for red, b for blue ,g for green,y for yellow
    bool isAlive = false;
    bool isJumping = false;
};
struct platformBuffer {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
    char type = 'u';// u for undefined, s for static, m for moving
    
};