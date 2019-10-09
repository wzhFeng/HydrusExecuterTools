
/****************************************************************************** 
 * 
 * 
 *  Copyright (c) 2019, Wenzhao Feng.
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

#ifndef IMPORTHYDRUSOUTPUTFILE_H
#define IMPORTHYDRUSOUTPUTFILE_H
#include <QString>
#include <memory>

class A_LevelObject;
class T_LevelObject;
class NodeInfoObject;
class BalanceObject;
class Obs_NodeObject;
class QSqlQuery;

class ImportHydrusoutputFile
{
public:
    ImportHydrusoutputFile();
    ~ImportHydrusoutputFile();
    bool Execute(std::shared_ptr<QSqlQuery> qry);
    void Gid(int value)
    {
        _gid=value;
    }
    void Filename(const std::string& value);
    bool operator!()
    {
        return !_valid;
    }
    operator bool()
    {
        return _valid;
    }

private :
    int _gid;
    bool _valid;
    std::unique_ptr<A_LevelObject> _paobj;
    std::unique_ptr<T_LevelObject> _ptobj;
    std::unique_ptr<NodeInfoObject> _pnobj;
    std::unique_ptr<BalanceObject> _pbobj;
    std::unique_ptr<Obs_NodeObject> _poobj;
    QString GetALevelSql();
    QString GetNodinfoSql();
    QString GetTLevelSql();
    QString GetBalancesql();
    QString GetObsNodesql();
    QString GetUpdateSelectorsql();
};

#endif // IMPORTHYDRUSOUTPUTFILE_H