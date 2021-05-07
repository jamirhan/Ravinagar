#include "Server.h"

RawCommand Server::Get() {
    if (temp == 0) {
        return RawCommand("CreateGraph;x^2 + 2x + 9", 1);
    } else if (temp == 1) {
        return RawCommand("CreateUnit;Spy;1;OnOwn", 1);
    } else if (temp == 2) {
        return RawCommand("CreateTrap;Clone;2;2", 1);
    } else if (temp == 3) {
        return RawCommand("ExitIntoSpace;2;2", 1);
    } else if (temp == 4) {
        return RawCommand("Capture;x^5 + x^2", 1);
    } else if (temp == 5) {
        return RawCommand("DestroyOwnGraph;1", 1);
    } else if (temp == 6) {
        return RawCommand("CreateUnit;Spy;1;OnCaptured", 1);
    }
    return RawCommand(".", 1);
}

Server::Server() = default;

Server* Server::GetInstance() {
    if (!inst)
        inst = new Server();
    return inst;
}
