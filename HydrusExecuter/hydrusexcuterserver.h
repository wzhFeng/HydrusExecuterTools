/****************************************************************************** 
 * 
 * 
 *  Copyright (c) 2020, Wenzhao Feng.
 *  All rights reserved.
 * 
 *  See the file COPYING in the top directory of this distribution for
 *  more information.
 *  
 *  THE SOFTWARE IS PROVIDED _AS IS_, WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 *  DEALINGS IN THE SOFTWARE.  
 *  
 *****************************************************************************/ 

#ifndef HYDRUSEXCUTERSERVER_H
#define HYDRUSEXCUTERSERVER_H

#include "hydrusexcuter.h"

class HydrusExecuterServer: public HydrusExecuter
{
public:
    HydrusExecuterServer()=default;
protected:
    virtual bool GetId(int & gid);
    virtual bool PrepareParameterFile(int gid);
    virtual bool ExecuteHydrus(int gid);
    virtual bool EnterRunning(int gid);
    virtual bool EnterFail(int gid, std::string &reason);
    virtual bool EnterTimeout(int gid);
    virtual bool EnterComplete(int gid, std::string &result);
};


#endif // HYDRUSEXCUTERSERVER_H
