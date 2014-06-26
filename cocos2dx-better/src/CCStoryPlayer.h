/****************************************************************************
 Author: Luma (stubma@gmail.com)
 
 https://github.com/stubma/cocos2dx-better
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __CCStoryPlayer__
#define __CCStoryPlayer__

#include "cocos2d.h"
#include "CCMoreMacros.h"

NS_CC_BEGIN

class CCStoryLayer;
class CCStoryCommand;

/// player of story command sequence
class CCStoryPlayer : public CCObject {
private:
    /// fetch next command
    void fetchNextCommand();
    
    /// execute one command
    void executeCurrentCommand();
    
public:
    CCStoryPlayer();
    virtual ~CCStoryPlayer();
    static CCStoryPlayer* create(CCStoryLayer* owner);
    
    /// init
    virtual bool initWithOwner(CCStoryLayer* owner);
    
    /// start
    void start();
    
    CC_SYNTHESIZE(CCStoryLayer*, m_owner, Owner);
    CC_SYNTHESIZE(CCStoryCommand*, m_curCmd, CurrentCommand);
    CC_SYNTHESIZE(int, m_curCmdIndex, CurrentCommandIndex);
    CC_SYNTHESIZE_READONLY_BOOL(m_done, Done);
    CC_SYNTHESIZE_BOOL(m_curCmdDone, CurrentCommandDone);
};

NS_CC_END

#endif /* defined(__CCStoryPlayer__) */